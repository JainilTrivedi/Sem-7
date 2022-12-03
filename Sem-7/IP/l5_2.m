img = imread('cameraman.tif');
img = imresize(img, 0.5);

[c,r] = size(img);
diff = (r-1)/(2*r-1);

c = 2*c;
r = 2*r;

X = zeros(r,c);
Y = zeros(r,c);

X(1,1) = 1;
Y(1,1) = 1;

for i=1:1:r
    X(i,1)=1;
end

for i=1:1:c
    Y(1,i)=1;
end

for i=1:1:r
    prevX = 1;
    for j=2:1:c
        X(i,j) = prevX + diff;
        prevX = X(i,j);
    end
end

for i=1:1:c
    prevY = 1;
    for j=2:1:r
        if(i == 1 && j == 1)
            continue;
        end
        Y(j,i) = prevY + diff;
        prevY = Y(j,i);
    end
end

newImg = zeros(r,c);
for i=1:1:r
    for j=1:1:c
        newImg(i,j) = img(round(Y(i,j)),round(X(i,j)));
    end
end

imshow((newImg),[]);
