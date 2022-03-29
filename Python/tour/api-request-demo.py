
import requests

response = requests.get('https://api.github.com/repos/lungchin-tw/Practices')
print(response)
print(f'Type:{type(response.text)}, Length:{len(response.text)}')
obj = response.json()
print(f'Type:{type(obj)}, Length:{len(obj)}')

for key in obj:
    print(key)