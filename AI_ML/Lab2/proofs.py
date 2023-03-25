import math
import logging
logging.basicConfig(
    level=logging.DEBUG,
    format="%(ascname)s in %(funcname)s\n: %(message)s"
)
if __name__ == "__main__":
    print("Trigonometric functions finder:")
    pinf = 1.633123935319537e+16
    ninf = 6.123233995736766e-17
    try:
        while True:
            c1 = input(
                "Want to give angles in degrees or radians? (r for rad, d for deg):\n")
            if c1[0].lower() == 'r':
                r = float(input("Radian value:"))
            elif c1[0].lower() == 'd':
                d = float(input("Degree value:"))
                r = math.radians(d)
            else:
                logging.debug(
                    "Unknown type of angle: only options {d,r} allowed")
                continue
            cs = math.cos(r)
            sn = math.sin(r)
            tn = math.tan(r)
            if cs != 0:
                sc = 1/cs
            if sn != 0:
                csc = 1/sn
            if tn != 0:
                ct = 1/tn
            # cosx/(secx+tanx) = 1-sinx
            print("Proofs:\n"+"-"*20)
            print("\ncosx/(secx+tanx) = 1-sinx")
            lhs = cs/(sc+tn)
            rhs = 1-sn
            print("{} ?= {}".format(lhs, rhs))
            print("\ncosecx+cotx = cot(1/2 x)")
            lhs = csc + ct
            tc = math.cos(r/2)
            ts = math.sin(r/2)
            rhs = tc/ts
            print("{} ?= {}".format(lhs, rhs))
            # (secx+1)/sec2 x = sin2 x / (secx - 1)
            print("\n(secx+1)/sec2 x = sin2 x / (secx - 1)")
            lhs = (sc+1)/(sc*sc)
            rhs = (sn*sn)/(sc-1)
            print("{} ?= {}".format(lhs, rhs))
            # sin(90-b) = cos b
            print("\nsin(90-b) = cos b")
            pib2 = math.radians(90)
            lhs = math.sin(pib2-r)
            rhs = cs
            print("{} ?= {}".format(lhs, rhs))
            # sinx + cos x = root(2) * sin(pi/4 + x)
            print("\nsinx + cos x = root(2) * sin(pi/4 + x)")
            lhs = sn + cs
            # math.pi
            rhs = math.sqrt(2) * (math.sin(math.pi/4 + r))
            print("{} ?= {}".format(lhs, rhs))

            c = input("Enter Y to continue for another angle value:")
            if c[0].lower() != 'y':
                break
    except:
        logging.warning("Error encountered: check input carefully")
