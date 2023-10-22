# Icosphere Generator Library 🌐

**A powerful yet lightweight C++ library tailored for generating Icosphere meshes.**

<p align="center">
    <img src="Icosphere.png" alt="Icosphere Image 1" width="70%" height="50%">
    <img src="icosphere.png" alt="Icosphere Image 2" width="70%" height="50%">
</p>

---

## 📖 Introduction

The Icosphere Generator offers an advanced yet straightforward mechanism to produce vertices and indices for Icosphere meshes. An Icosphere, known as a polyhedron composed of equilateral triangle faces, stands out in 3D graphics. Its unique attribute of evenly distributing vertices proves invaluable for operations like spherical environment mapping.

## 🌟 Features

- 🛠 **Easy Generation**: Swiftly produce vertices and indices for an Icosphere mesh.
- 🔍 **Customizable Detail**: Adjust the level of detail as per your requirement using the sample parameter.
- 🚀 **Optimized Memory Management**: Ensure efficient storage for vertices and indices.

## 🛠 Installation

Integrating the Icosphere Generator is a breeze. Just incorporate the `icosphere_generator.hpp` header into your project.

## 📚 Usage

1. **Initialize an Icosphere Object**: Configure the desired number of samples.
   ```cpp
   IcosphereGenerator::Icosphere icosphere(2);  // Example: samples = 2

# Usage:

## Create an Icosphere object with the desired number of samples:
IcosphereGenerator::Icosphere icosphere(2);  // For example: samples = 2

## Generate the mesh:
icosphere.generate();

## Access the vertices and indices:
std::vector<float> vertices = icosphere.vertices;
std::vector<unsigned int> indices = icosphere.indices;

# Contributing:
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change. Make sure to update tests as appropriate.

# License:
This project is licensed under the MIT License. For more information, see MIT License.
