# Dataframeの末尾の'値'を抽出する方法
```python 
print(df.iloc[-1]['sepal_length'])
# 5.9
```

```python
import pandas as pd
df = pd.DataFrame({
    'name':
    ['orange','banana','lemon','mango','apple'],
    'price':
    [2,3,7,21,11],
    'stock':
    ['Yes','No','Yes','No','Yes']
})
print(df.at[df.index[-1],'stock'])
# Yes
```
```python
# Original
#       name  age state  point
# 0    Alice   24    NY     64
# 1      Bob   42    CA     92
# 2  Charlie   18    CA     70
# 3     Dave   68    TX     70
# 4    Ellen   24    CA     88
# 5    Frank   30    NY     57

df_s = df.sort_values(['age', 'state'], ascending=[True, False])
print(df_s)
#       name  age state  point
# 2  Charlie   18    CA     70
# 0    Alice   24    NY     64
# 4    Ellen   24    CA     88
# 5    Frank   30    NY     57
# 1      Bob   42    CA     92
# 3     Dave   68    TX     70
```

# mapでのDataframe列一括変換
```python
species={'setosa':1,'versicolor':2,'virginica':3}

df['Species_num2']=df['species'].map(species)

# sepal_length  sepal_width      ...       species  Species_num2
#0           5.1          3.5      ...        setosa             1
#1           4.9          3.0      ...        setosa             1
#2           4.7          3.2      ...        setosa             1
#3           4.6          3.1      ...        setosa             1
#4           5.0          3.6      ...        setosa             1
```


