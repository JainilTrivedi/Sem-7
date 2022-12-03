##Q1
A = imread('pout.tif');
for i=0:1:7
B = A/(2^i);
  subplot(3,3,i+1);
  imshow(B,[]);
end
