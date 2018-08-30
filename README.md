1.It is a c++ program.

2. It contains two structures.Owner and node.
  (i) Structure owner contains information related to owner like(owner value,owner id,owner value)
  (ii)Structure owner contains field now(for timestamp),nodenumber(unique number),nodeId(unique string consists of          timestamp_Owner_name),on(refer to owner structure),genesisRefernceNodeId(contain reference to root),Child_reference(it will contain all reference to childern),hv(hash value for every node);
 
3. function newNode() is used to create node of owner type.

3. function newNode2() is used to create node of node type.

4.Logic to insert node in a tree is implemented in void insert() function 

5.Function diameter() calculates length of longest chain from root or any node in the tree. 

