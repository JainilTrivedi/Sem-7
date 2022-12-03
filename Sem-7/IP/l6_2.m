me = imread('ME.png');
me_g = rgb2gray(me);

weighted_filter = [2,4,2;4,8,4;2,4,2];
sum_weighted_filter = sum(sum(weighted_filter));
window = weighted_filter*(1/sum_weighted_filter);
window2 = (1/9)*ones(3,3);
output = spatial_filter(me_g,window);
subplot(2,1,1);
imshow(uint8(output));
title('3x3 Weighted Filter');

output2=spatial_filter(me_g,window2);
subplot(2,1,2);
imshow(uint8(output2));
title('3x3 Std Filter');
