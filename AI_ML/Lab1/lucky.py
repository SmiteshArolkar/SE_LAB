import logging
logging.basicConfig(
    level=logging.DEBUG,
    format="Time: %(asctime)s; %(funcName)s : \n %(message)s"
)

# to generate lucky nums


def luckyList(n: int):
    # create list of first n integers
    if n < 0:
        return []
    elif n < 2000:
        nums = list(range(1, 10*n+1))
    else:
        nums = list(range(1, 12*n+1))
    # print(nums)
    # start with i = 2, then take the value at iTh location
    # in the nums list as the pivot to be removed
    # for now print the pivot number
    oLen = len(nums)
    numLen = oLen
    i = 2
    j = 2
    while j < len(nums):
        logging.debug("len(nums) == {}\nNums right now:".format(len(nums)))
        logging.debug(nums)
        indicesToRemove = []
        # now create a list of the removable using range
        indicesToRemove = list(range(j, numLen+1, j))
        logging.info("removing these indices: j = " + str(j))
        logging.debug([i-1 for i in indicesToRemove])
        for x in indicesToRemove[::-1]:
            # print(x,end=" ")
            del nums[x-1]
        numLen = len(nums)
        j = nums[i-1]
        i += 1
    return nums[:n]


if __name__ == "__main__":
    print("Lucky number generator")
    while True:
        upperBound = int(input("Enter n:"))
        result = luckyList(upperBound)
        print(result)
        logging.info("Len:"+str(len(result)))
        choice = input("Enter yes to continue, anything else to break:")
        if choice[0].upper() != "Y":
            print("Thank you for using the lucky number generator")
            break
