import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    dataframe_shape = []
    dataframe_shape.append(players.shape[0])
    dataframe_shape.append(players.shape[1])

    return dataframe_shape