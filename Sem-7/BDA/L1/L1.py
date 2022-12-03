# import pandas as pd

# excel = pd.read_excel('FINAL450.xlsx')
# df = pd.DataFrame(excel)
# df.to_csv("excelToCSV.csv",index=False)


# import sqlite3
# import json
# from textwrap import wrap
# from dict2xml import dict2xml as xmlify
# conn = sqlite3.connect("C:\\Users\\Jainil\\Downloads\\SQLiteStudio\\BDA_lab1")
# cur = conn.cursor()
# cur.execute('SELECT * FROM cricket')

# columns = list(map(lambda x:x[0],cur.description))
# records = cur.fetchall()
# record_list = []
# for record in range(0,len(records)):
#     record_dict = {}
#     for column in range(0,len(columns)):
#         record_dict[columns[column]] = records[record][column]
#     record_list.append(record_dict)

# json_obj = json.dumps(record_list)
# xml_boj = xmlify(record_list,wrap='cricket',indent=" ")

# json_file = open("jsonfile.json","w")
# json_file.write(json_obj)

# xml_file = open("xmlfile.xml","w")
# xml_file.write(xml_boj)

# conn.close()

import pandas as pd
import matplotlib.pyplot as plt

ds = pd.read_csv("Q8.csv")
topic = ds['Topic']
questions = ds['Questions']
x=list(topic)
y=list(questions)
plt.legend('topic','solved')
plt.pie(y,labels=x,autopct='%.2f%%')
plt.savefig("piechart_Q8.pdf",format="pdf")
