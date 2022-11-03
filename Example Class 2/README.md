# Djikstra Algorithm

For this example class, we are required to use two possible methods for djikstra algorithm</br>
(a) Adjacency Matrix + Array as priority queue</br>
(b) Adjacency List + Heap Sort as priority queue (Use hash map)</br>

Assumptions:</br>
No negative weights</br>
Every vertice is connected to another vertice</br>

Data Structures:</br>
S - solution set</br>
distance - array to store the distance from source to node</br>
pi - predecessors to store the vertice node is connected to</br>

Time Complexity:</br>
(a) O(V^2)</br>
(b) O((|V| + |E|)log|V|)</br>
