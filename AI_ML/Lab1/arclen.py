import logging,radianDegrees
logging.basicConfig(
  level=logging.DEBUG, # CHANGE TO logging.debug to enable logging
  format="Time:%(asctime)s in %(funcName)s\n%(message)s"
)
def arclen(r,d):
  ratio = d/360
  logging.info("Ratio is"+str(ratio))
  return 2*radianDegrees.pi*r*ratio
if __name__ == "__main__":
  print("Program to calculate arclength of an angle:")
  while True:
    r = float(input("Enter radius"))
    d = float(input("Enter angle in degrees:"))
    al = arclen(r,d)
    print("Arclength is: {}".format(al))
    choice = input("Enter yes to continue, anything else to break:")
    if choice[0].upper() != "Y":
      print("Thank you for using the angle unit convertor")
      break
