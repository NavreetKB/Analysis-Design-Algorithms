import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

data = pd.read_csv('magicData.csv')
sizes = data['Size']
times = data['time(nanoseconds)']

n_square=sizes**2
n_square= n_square* (max(times)/max(n_square))
plt.figure(figsize=(10, 6)) 
plt.plot(sizes, times,label='Timecomplexity' ,marker='o', linestyle='-', color='b')  
plt.plot(sizes,n_square,marker='o', linestyle='-', color='r',label='n^2')

plt.xlabel('Array Size')
plt.ylabel('Average Time (microseconds)')
plt.title('Average Time vs. Array Size')
plt.legend()
plt.show()  

