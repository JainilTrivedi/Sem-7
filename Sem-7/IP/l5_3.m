A = imread('cameraman.tif');
A = imresize(A,0.5);
B = zeros(128,384);
B = double(B);

for i=1:1:128
  for j=1:1:128
    x = i*2+j;
    B(j,x) = A(j,i);
  end
end
subplot(2,2,1);
imshow(B,[]);
B1=B;
tform = maketform('affine',[1 0 0; 0.5 1 0; 0 0 1]);
B1 = imtransform(A,tform);
subplot(2,2,2);
imshow(B1,[]);

C = zeros(512,128);
C = double(C);
for i=1:1:128
   for j=1:1:128
    y = i+j*3;
    C(y,i) = A(j,i);
   end
end
subplot(2,2,3);
imshow(C,[]);
C1=C;
tform = maketform('affine',[1 0 0; 0.5 1 0; 0 0 1]);
C1 = imtransform(A,tform);
subplot(2,2,4);
imshow(C1,[]);


