import pandas as pd
import datashader as ds
from datashader import transfer_functions as tf
from datashader.utils import export_image
import holoviews as hv
from holoviews import opts
import numpy as np

hv.extension('bokeh')

# Reemplaza 'csv_file_path' con la ruta real a tu archivo CSV
csv_file_path = 'plotDataSet.csv'

# Cargar el DataFrame desde un archivo CSV sin especificar dtype inicialmente
df = pd.read_csv('plotDataSet.csv')

# Opcionalmente, convertir las columnas al tipo deseado si no se detectaron automáticamente
df['id'] = pd.to_numeric(df['id'], errors='coerce')
df['OnesNumber'] = pd.to_numeric(df['OnesNumber'], errors='coerce')

# Ahora, sigue el procedimiento con Datashader para visualizar los datos
canvas = ds.Canvas(plot_width=800, plot_height=400, x_range=(df.id.min(), df.id.max()), y_range=(df.OnesNumber.min(), df.OnesNumber.max()))
agg = canvas.points(df, 'id', 'OnesNumber')
img = tf.shade(agg, how='eq_hist')

export_image(img, filename='mi_imagen_datashader')
# Hacer la imagen interactiva con HoloViews, si estás trabajando en un Jupyter Notebook
img_hv = hv.RGB(np.array(img.to_pil()), bounds=(df.id.min(), df.OnesNumber.min(), df.id.max(), df.OnesNumber.max()))
img_hv.opts(opts.RGB(width=800, height=400, xaxis=None, yaxis=None))

# Muestra la imagen generada
img_hv
