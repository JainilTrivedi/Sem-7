##histogram equalisation

A = imread('ex_contrast.tif');

B = zeros(255,1);
[c,r] = size(A);

for i=0:1:255
  B(i+1,1)=sum(A(:)==i);
end

B = B/(r*c);
for i=1:1:255
  B(i+1,1) = B(i+1,1)+B(i,1);
end

for i=0:1:255
  B(i+1,1) = round(B(i+1,1)*255);
end

C = zeros(r,c);

for i=1:1:r
  for j=1:1:c
    C(i,j) = B(A(i,j)+1);
  end
end

imshow(A);
figure,imshow(C,[]);
