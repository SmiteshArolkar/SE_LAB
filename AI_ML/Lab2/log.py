from math import log,log10
import logging
logging.basicConfig(
  level=logging.DEBUG,
  format="%(asctime)s , in %(funcName)s\n %(message)s"
)
if __name__=="__main__":
  print("Log(e) calculator")
  while True:
    try:
      x: float = float(input("Enter x:"))
      y: float = log(x)
      print("log({}) = {}".format(x,y))
      c = input("Enter y to continue, anything else to exit: ")
      if c[0].lower() != 'y':
        break
    except:
      logging.warning("Encountered error: check input carefully")
  