import logging
logging.basicConfig(
  level=logging.WARNING, # CHANGE TO logging.debug to enable logging
  format="Time:%(asctime)s in %(funcName)s\n%(message)s"
)
pi = 3.141592653589793
def degree2rad(deg):
  # divide by 180, multiply by pi
  return ((deg/180) * pi)
def radian2deg(rad):
  return ((rad/pi)*180)
if __name__ == "__main__":
  print("Program to convert radians to degrees and vice versa:")
  while True:
    c = input("Enter r to convert to radians, d to convert to degrees:")
    if c.upper() == "R":
      deg = float(input("Enter degrees:"))
      r = degree2rad(deg)
      print("The radian value for {} = {} rad".format(deg,r))
    elif c.upper() == "D":
      rad = float(input("Enter radians:"))
      deg = radian2deg(rad)
      print("The degree value for {} = {} deg".format(rad,deg))
    choice = input("Enter yes to continue, anything else to break:")
    if choice[0].upper() != "Y":
      print("Thank you for using the angle unit convertor")
      break
