%% اسکریپت تولید تست برای پوشش کامل MCDC
clear; clc;

% 1. تنظیمات زمان
T_step = 0.1;       % گام زمانی (باید با Solver مدل یکی باشد)
T_final = 80;       % مدت زمان کل تست
time = (0:T_step:T_final)'; 
n = length(time);

% 2. تعریف ماتریس دما (4 ستون برای 4 اتاق)
% مقدار اولیه: همه اتاق‌ها 15 درجه (سرد) -> بخاری‌ها باید روشن شوند
x_vals = ones(n, 4) * 15; 

%% فاز 1: تست روشن/خاموش (Hysteresis)
% زمان 10 تا 20: دما بالا می‌رود تا بخاری‌ها خاموش شوند (بالای 20)
% فرض: On=19, Off=20
for i = 1:n
    t = time(i);
    if t > 10 && t <= 20
        % افزایش دما از 15 به 22
        x_vals(i, :) = 15 + (t-10) * (7/10); 
    elseif t > 20
        % دما را روی 21 نگه می‌داریم (همه بخاری‌ها خاموش)
        x_vals(i, :) = 21; 
    end
end

%% فاز 2: تست جابجایی (Migration) - انتقال از اتاق 2 به 1
% فرض: در لحظه t=30، بخاری‌ها خاموش و آماده‌اند.
% شرایط جابجایی: x_source < get_target ؟ نه، معمولا x_source > x_target
% سناریو: اتاق 1 یخ می‌زند، اتاق 2 گرم است. بخاری باید برود به 1.

% بازه زمانی 30 تا 50
ind_phase2 = (time > 30) & (time <= 50);
x_vals(ind_phase2, 1) = 10; % اتاق 1 خیلی سرد (نیاز به بخاری)
x_vals(ind_phase2, 2) = 21; % اتاق 2 گرم (بخاری آزاد)
x_vals(ind_phase2, 3) = 21; 
x_vals(ind_phase2, 4) = 21;

%% فاز 3: تست جابجایی دیگر - انتقال از اتاق 3 به 4
% بازه زمانی 50 تا 70
ind_phase3 = (time > 50) & (time <= 70);
x_vals(ind_phase3, 1) = 21;
x_vals(ind_phase3, 2) = 21;
x_vals(ind_phase3, 3) = 22; % اتاق 3 گرم
x_vals(ind_phase3, 4) = 8;  % اتاق 4 یخ زده

%% 3. ساخت آبجکت Timeseries برای سیمولینک
% نام این متغیر باید دقیقاً test_x باشد (همانی که در بلوک From Workspace نوشتیم)
test_x = timeseries(x_vals, time);

disp('Variable "test_x" created in Workspace successfully.');
disp('Now run the Harness simulation.');
