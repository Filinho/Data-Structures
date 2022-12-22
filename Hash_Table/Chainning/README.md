# Chainning

Chaining is a strategy to deal with collisions in the hash table, which works by creating a linked list with all the collisions of that table's vector index.

The biggest advantage of the chaining strategy also becomes its biggest disadvantage, by using the linked list resource to deal with collisions, a table implemented with this method will never run out of space to insert new elements, however, for the same reason, lists formed in the nodes are getting longer and longer and the time to fetch a piece of data is proportional to its distance from the beginning of the list.
