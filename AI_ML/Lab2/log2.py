from math import log2
if __name__=="__main__":
  print("Log2 calculator")
  while True:
    x: float = float(input("Enter x:"))
    y: float = log2(x)
    print("log2 {} = {}".format(x,y))
    c = input("Enter y to continue, anything else to exit: ")
    if c[0].lower() != 'y':
      break
  