import logging
logging.basicConfig(
  level=logging.DEBUG, # CHANGE TO logging.debug to enable logging
  format="Time:%(asctime)s in %(funcName)s\n%(message)s"
)
def isAbundant(n):
  """
  an abundant number is the one for which, the sum of its proper divisors is greater
  than the number itself.
  This is a boolean function to determine whether a number is abundant
  """
  # algo:
  # find the sum of divisors
  # if sum exceeds return true, else false
  sum = 0
  for i in range(1,n):
    if n%i == 0:
      sum+= i
  if sum > n:
    return True
  else:
    return False
if __name__ == "__main__":
  print("Program to calculate find whether a number is an abundant number:")
  while True:
    n = int(input("Enter n:"))
    if isAbundant(n):
      print("{} is an abundant number".format(n))
    else:
      print(f"{n} is not an abundant number")
    
    choice = input("Enter yes to continue, anything else to break:")
    if choice[0].upper() != "Y":
      print("Thank you for using the angle unit convertor")
      break
