me = imread('ME.png');
subplot(2,2,1);
imshow(me);
title('1');
meg = rgb2gray(me);
subplot(2,2,2);
imshow(meg);
title('2');

% function defination at the end of the file/script
s = decreaseContrast(meg);
subplot(2,2,3);
imshow(s,[]);
title('3');
%piece wise linear operation
m1=[];
m2=[];
m3=[];


smin2=0;
smax2=110;
smin3=111;
smax3=160;
smin4=161;
smax4=255;

s=double(s);
[r,c]=size(s);
for i=1:r
    for j=1:c
        if s(i,j) <=smax2
            m1(end+1)=s(i,j);
        elseif s(i,j)>smax2 && s(i,j) <=smax3          
            m2(end+1)=s(i,j);
        else
            m3(end+1)=s(i,j);
        end
    end
end


rmin1=min(min(m1));
rmax1=max(max(m1));

rmin2=min(min(m2));
rmax2=max(max(m2));

rmin3 =min(min(m3));
rmax3=max(max(m3));
final = [];
for i=1:r
    for j=1:c
        if s(i,j)<=smax2
            final(i,j)=((smax2-smin2)/(rmax1-rmin1))*((s(i,j))-rmin1)+smin2;
%             if 1==1 && j==1
%                 s(i,j)
%             end

        elseif s(i,j)>smax2 && s(i,j)<=smax3
            final(i,j)= ((smax3-smin3)/(rmax2-rmin2))*((s(i,j))-rmin2)+smin3;
        else
            final(i,j)= ((smax4-smin4)/(rmax3-rmin3))*((s(i,j))-rmin3)+smin4;
        end
    end
end

subplot(2,2,4);
imshow(final,[]);
title('4');
function s = decreaseContrast(meg)
%              smax=255;
%              smin=70;
             rmax=max(max(meg));
             rmin=min(min(meg));
             smax = max(max(meg));
             smin=min(min(meg));
             
             s = double(((smax-smin)/(rmax-rmin)))*((meg-rmin))+smin;
end