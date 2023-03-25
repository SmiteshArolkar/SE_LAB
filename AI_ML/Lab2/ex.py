from math import exp
import logging
logging.basicConfig(
  level=logging.DEBUG,
  format="%(asctime)s , in %(funcName)s :\n%(message)s"
)
if __name__=="__main__":
  print("Exp calculator")
  while True:
    try:
      x: float = float(input("Enter x:"))
      y: float = exp(x)
      print("exp({}) = {}".format(x,y))
      c = input("Enter y to continue, anything else to exit: ")
      if c[0].lower() != 'y':
        break
    except ValueError:
      logging.warning("Invalid input, closing")
    except OverflowError:
      logging.warning("Input x is too large (try x < 709)")