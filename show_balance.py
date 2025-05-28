import pandas as pd
import plotly.express as px
import sys


csv_file = 'balance_data.csv'
if len(sys.argv) > 1:
    csv_file = sys.argv[1]


df = pd.read_csv(csv_file)


fig = px.line(df, x='Transaction', y='Balance', markers=True,
              title='Evolution of the Personal Balance Sheet')

fig.update_layout(
    xaxis_title='Transaction Number',
    yaxis_title='Balance ($)',
    hovermode='x unified'  
)

fig.show()
