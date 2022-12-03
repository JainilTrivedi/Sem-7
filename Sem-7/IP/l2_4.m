%Q1
me = imread('me.png');
%subplot(1,3,1)
%imshow(me);

me_gray = rgb2gray(me);
%subplot(1,3,2);
%imshow(me_gray);

%negative
%negative = 255-me_gray;
%subplot(1,3,3);
%imshow(negative);


%Q2
% img = imread('ex_log.tif');
% subplot(2,2,1);
% imshow(img);
% 
% 
% double_img = double(img);
% double_log_transform = log(1+double_img);
% subplot(2,2,2);
% imshow(double_log_transform,[]);
% 
% img2 = im2double(img);
% subplot(2,2,3);
% imshow(img2);
% 
% log_transform = 8*log(img2+1);
% subplot(2,2,4);
% imshow(log_transform);

% Q3
% TO_BRIGHTEN = imread('ex_power1.tif');
%subplot(1,2,1);
%imshow(TO_BRIGHTEN);

% TO_BRIGHTEN = imread('ex_power2.tif');
% subplot(1,2,1);
% imshow(TO_BRIGHTEN);
% TO_BRIGHTEN_DOUBLE = double(TO_BRIGHTEN);
% TO_BRIGHTEN_POWER_LAW = power(TO_BRIGHTEN_DOUBLE,3);
% subplot(1,2,2);
% imshow(TO_BRIGHTEN_POWER_LAW,[]);

% img_p2 = imread('ex_power2.tif');
% subplot(1,2,1);
% imshow(img_p2);
% img_p2_d = double(img_p2);
% img_p2_dark = power(img_p2_d,3);
% subplot(1,2,2);
% imshow(img_p2_dark,[]);

% Q4
% subplot(1,3,1);
% imshow(me_gray);
% me_oe = me_gray-100;
% subplot(1,3,2);
% imshow(me_oe);
% 
% me_oe_d = double(me_oe);
% me_oe_power_law = power(me_oe_d,.2);
% subplot(1,3,3);
% imshow(me_oe_power_law,[]);

% Q5
% subplot(1,3,1);
% imshow(me_gray);
% me_ue = me_gray+100;
% subplot(1,3,2);
% imshow(me_ue);
% 
% me_ue_d = double(me_ue);
% me_ue_power_law = power(me_ue_d,2.3);
% subplot(1,3,3);
% imshow(me_ue_power_law,[]);

% Q6
% A = [
%     7,12,8;
%     16,9,6;
%     10,15,1;
%     ];
% rmax = max(max(A));
% rmin= min(min(A));
% smax=255;
% smin=0;
% S = ((smax-smin)/(rmax-rmin))*(A-rmin)+smin;
% A
% S

% Q7
% img = imread('ex_contrast.tif');
% subplot(1,3,1);
% imshow(img);
% 
% %contrast stretching
% rmax=max(max(img));
% rmin=min(min(img));
% rmin = double(rmin);
% 
% smax=255;
% smin=70;
% S = double(((smax-smin)/(rmax-rmin)))*((img-rmin))+smin;
% subplot(1,3,2);
% imshow(S);
% 
% %thresholding
% s=double(S);
% threshold = mean(mean(s));
% [r,c] = size(s);
% img2 = zeros(r,c);
% for i=1:r
%     for j=1:c
%         if(s(i,j) >= threshold)
%             img2(i,j)=1;
%         else
%             img2(i,j)=0;
%         end
%     end
% end
% 
% subplot(1,3,3);
% imshow(img2);






