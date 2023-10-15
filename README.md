# Icosphere Generator Library
A standalone library implemented in a header file. The algorithm efficiently generates the vertex and index buffer of a unit icosphere.

### function header:
void generateIcosphere(std::vector<float>* vertices, std::vector<unsigned int>* indices, int samples);

### function arguements
std::vector<float>* vertices        : vertex buffer address
std::vector<unsigned int>* indices  : index buffer address
int samples                         : number of times the original unit is subdivided

### Vertex buffer format
Vertex buffer has 6 attributes in this implementation:
x,y,z coordinates and r,g,b values. Modify the file according to your needs.
  
### how it works
A unit octahedral is first generated. Then each face of the octahedral is subdivided into smaller triangles sample number of times. So if sample=0, then it is not divided.
Finally the coordinate of all of the generated vertices are normalized which forms the following sample icosphere.
### sample shot
![image](icosphere.png)
