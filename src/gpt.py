import os
import openai 

openai.api_key = os.getenv("OPENAI_API_KEY")

response = openai.ChatCompletion.create(
    model = "gpt-3.5-turbo", 
    messages=[
            {"role": "system", "content": "你是一个先知先觉的著名算命专家，尤其擅长给人推算学业和姻缘的运势"},
            {"role": "user", "content": "范心豪是我的舍友，他今年考研失败了（南京大学物理系），今年他还是很优哉游哉，他今年能考上么？"},
            {"role": "user", "content": "他的出生时间是2000年12月9日,本科就读于中国的东北大学秦皇岛分校控制工程学院机械专业，在本届阶段参与过多次科创项目"}
    ]    
)

print(response['choices'][0]['message']['content'])