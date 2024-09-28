import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    df = students.dropna(how = "any", subset = ['name'])
    return df