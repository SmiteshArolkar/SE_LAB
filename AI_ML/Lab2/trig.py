import math,logging
logging.basicConfig(
  level=logging.DEBUG,
  format="%(ascname)s in %(funcname)s\n: %(message)s"
)
if __name__=="__main__":
  print("Trigonometric functions finder:")
  print("+ infinity: 1.633123935319537e+16")
  print("- infinity:  6.123233995736766e-17")
  while True:
    c1 = input("Want to give angles in degrees or radians? (r for rad, d for deg):\n")
    if c1[0].lower() == 'r':
      r = float(input("Radian value:"))
    elif c1[0].lower() == 'd':
      d = float(input("Degree value:"))
      r = math.radians(d)
    else:
      logging.debug("Unknown type of angle: only options {d,r} allowed")
      continue
    while True:
      c = input("S for sin, C for cos, T for tan, anything else to exit:")
      if c[0].lower() == 's':
        t = "Sin"
        x = math.sin(r)
      elif c[0].lower() == 'c':
        t = "Cos"
        x = math.cos(r)
      elif c[0].lower() == 't':
        t = "Tan"
        x = math.tan(r)
      else:
        # logging.debug("Trig function not recognised")
        break
      print("Value of {}(r) is {}".format(t,str(x)))
    c = input("Enter Y to continue for another angle value:")
    if c[0].lower() !='y':
      break