me = imread('ME.png');
me_g = rgb2gray(me);

j=1;
for i=3:2:10
  window = (1/(i*i))*ones(i,i);
  output = spatial_filter(me_g,window);
  subplot(2,4,j);
  output = uint8(output);
  imshow(output);
  title([num2str(i),'x',num2str(i)]);
  subplot(2,4,j+1);
  imshow(imfilter(me_g,window));
  title(['Using function',num2str(i),'x',num2str(i)]);
  j=j+2;
end
