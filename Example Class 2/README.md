The djikstra algorithm

For this example class, we are required to use two possible methods for djikstra algorithm
(a) Adjacency Matrix + Array as priority queue
(b) Adjacency List + Heap Sort as priority queue (Use hash map)

Assumptions:
No negative weights
Every vertice is connected to another vertice

Data Structures:
S - solution set
distance - array to store the distance from source to node
pi - predecessors to store the vertice node is connected to

Time Complexity:
(a) O(V^2)
(b) O((|V| + |E|)log|V|)
