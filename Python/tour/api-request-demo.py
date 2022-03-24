
import requests

response = requests.get('https://github.com/lungchin-tw')
print(response)
print(f'Type:{type(response.text)}, Length:{len(response.text)}')
