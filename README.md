# Preffered_Distance
Given a number of cities in a distant country, where different cities are connected by means of two-lane roads to the cities
others. Not all cities are connected to other cities.
A citizen who wants to reach his destination can pass through any of the cities connected to his city, and from there continue to the cities
to which those cities are connected. The citizens of the country always prefer to move to a nearby city with a very small number,
from which there is a road to the destination that does not pass through the city twice.
We will use the following settings:
focal - a city from which the citizen originates.
Destination - a city where the citizen wants to go.
Preferred route - a route from the hub to the destination which at each pass selects the city with the least number of all
The cities through which there is a route to the destination that does not go through a city that has already been visited.
Preferred distance - the number of passes on the preferred route.
The program receives the cities in the country and the roads between them, then receives a focal point and destination, and finds
the preferred distance between them.
The algorithm for calculating the distance between the center and the destination is actually the recursive function TownDistance.
This is a homework assignment in the "Data Structures" course. One of the requirements of the assignment was to take this recursive function, and implement it without recursion.
This is actually the CancelRecurs function.
