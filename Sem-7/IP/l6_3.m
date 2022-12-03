me = imread('ME.png');
me_g = rgb2gray(me);
tmp = me_g;

for i=1:1:5
  window = (1/25)*ones(5,5);
  output = spatial_filter(tmp,window);
  tmp=output;
  subplot(1,5,i);
  imshow(uint8(output));
  title(['5x5  ',num2str(i),'th pass']);
end
