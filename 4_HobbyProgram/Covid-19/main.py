import pandas as pd
import os
os.chdir(os.path.dirname(os.path.abspath(__file__)))
df = pd.read_csv("patients.csv")
df.head()