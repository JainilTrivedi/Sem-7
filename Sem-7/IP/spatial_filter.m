function [ output] = spatial_filter( igray,window )
       [M,N]=size(igray);
       [m,n]=size(window);
       a=(m-1)/2;
       b=(n-1)/2;
       %igray=double(igray);
       new_img=zeros(M+2*a,N+2*b);
       new_img(a+1:a+M,b+1:b+N)=igray;
       for i=a+1:a+M
           for j=b+1:b+N
               temp=new_img(i-a:i+a,j-b:j+b);
               new_img(i,j)=sum(sum(temp.*window));
           end
       end
       output=new_img;
end


