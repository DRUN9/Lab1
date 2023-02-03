from matplotlib import pyplot as plt
from os import listdir

FIGURE = plt.figure()


def getPoints(fileName):
    with open(fileName, 'r') as file:
        data = file.readlines()

    data = list(map(lambda x: x[:-1], data))

    return data

def showImage(x, y, title=""):
    plt.plot(x, y)

    plt.title(title)
    plt.ylabel("Time")
    plt.xlabel("Data")

    plt.show()

def getImage(x, y, title=""):
    plt.clf()

    plt.plot(x, y)
    
    plt.title(title)
    plt.ylabel("Time, ms")
    plt.xlabel("Data")

    plt.savefig(f"Images\\{title}.png")


files = listdir("Tests")

for file in files:
    data = getPoints("Tests\\" + file)

    x = list(map(lambda x: int(x.split()[0]), data))
    y = list(map(lambda y: float(y.split()[1]), data))

    getImage(x, y, title=file.split('.')[0])

    
