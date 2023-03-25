import logging
logging.basicConfig(
  level=logging.WARNING, # CHANGE TO logging.debug to enable logging
  format="Time:%(asctime)s in %(funcName)s\n%(message)s"
)
def findRoots(a,b,c):
  """
  Function that finds the roots of a given quadratic equation
  or returns 0,0 if it has complex roots
  """
  d = (b**2) - 4 * a * c
  logging.info("D = "+str(d))
  sd = (-1*d) ** 0.5
  if d < 0:
    z = 2*a
    p = complex((-1*b)/z , (sd)/z)
    q = complex((-1*b)/z ,(-1)*(sd)/z)
    return p,q
  else:
    p = (-1*b + sd)/(2*a)
    q = (-1*b - sd)/(2*a)
  logging.info(f"Roots are: {p} and {q}")
  return (p,q)

if __name__ == "__main__":
  print("Program to solve quadratic equations:")
  while True:
    print("Enter a,b,c (from ax^2 + bx + c):")
    a = int(input("A:"))
    b = int(input("B:"))
    c = int(input("C:"))
    # print(a,b,c,sep=" | ")
    p,q = findRoots(a, b, c)
    print(f"Roots are: {p} and {q}")
    choice = input("Enter yes to continue, anything else to break:")
    if choice[0].upper() != "Y":
      print("Thank you for using the quadratic root finder")
      break
