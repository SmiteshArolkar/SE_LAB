import logging
logging.basicConfig(
  level=logging.DEBUG,
  format="%(asctime)s , in %(funcName)s \n%(message)s"
)
if __name__=="__main__":
  print("Absolute number calculator")
  while True:
    try:
      x: float = float(input("Enter any number:"))
      y: float = abs(x)
      print("Absolute value of {} is {}".format(x,y))
      c = input("Enter y to continue, anything else to exit: ")
      if c[0].lower() != 'y':
        break
    except:
      logging.warning("Error encountered: check input carefully")