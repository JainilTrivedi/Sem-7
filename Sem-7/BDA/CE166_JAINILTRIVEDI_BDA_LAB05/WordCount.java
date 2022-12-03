import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.*;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
public class WordCount {
    public static class TokenizerMapper extends Mapper < LongWritable,
        Text, Text, Text > {
            private Text word = new Text();
            private Text val = new Text();
            public void map(LongWritable key, Text value, Context context) throws IOException,
            InterruptedException {
                StringTokenizer tokenizer = new StringTokenizer(value.toString());
                String[] split=value.toString().split("->");
                String val1 = split[0];
                val.set(val1);
                if(split.length==1)
                    return;
                String[] friendIds=split[1].split(",");
                if(friendIds.length == 1)
                {
                    return;
                }
                for(int i=0;i<friendIds.length;i++)
                {
                    for(int j=i+1;j<friendIds.length;j++)
                    {
                        String tmp1= friendIds[i];
                        String tmp2 = friendIds[j];
                        String tmp3 = "";
                        if(tmp1.compareTo(tmp2) == -1)
                            tmp3 = tmp1+','+tmp2;
                        else
                            tmp3 = tmp2+','+tmp1;
                        word.set(tmp3);
                        context.write(word,val);
                    }
                }
            }
        }
    public static class IntSumReducer extends Reducer < Text, Text,
        Text, Text > {
            private Text result = new Text();
            public void reduce(Text key, Iterable < Text > values, Context context) throws
            IOException,
            InterruptedException {
                String ans="";
                for (Text val: values) {
                    ans += val;
                    ans += "  ";
                }
                result.set(ans);
                context.write(key, result);
            }
        }
    public static void main(String[] args) throws Exception {
        Configuration conf = new Configuration();
        Job job = Job.getInstance(conf, "word count");
        job.setJarByClass(WordCount.class);
        job.setMapperClass(TokenizerMapper.class);
        job.setCombinerClass(IntSumReducer.class);
        job.setReducerClass(IntSumReducer.class);
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);
        FileInputFormat.addInputPath(job, new Path(args[0]));
        FileOutputFormat.setOutputPath(job, new Path(args[1]));
        System.exit(job.waitForCompletion(true) ? 0 : 1);
    }
}
