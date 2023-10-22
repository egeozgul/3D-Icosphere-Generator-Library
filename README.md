# Icosphere Generator Library 🌐

**A powerful yet lightweight C++ library tailored for generating Icosphere meshes.**

<p align="center">
    <img src="Icosphere.png" alt="Icosphere Image 1" width="70%" height="50%">
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

2. **Generate The Icosphere Mesh**
   ```cpp
   icosphere.generate();

3. **Retrieve the Vertices and Indices**
   ```cpp
   std::vector<float> vertices = icosphere.vertices;
   std::vector<unsigned int> indices = icosphere.indices;

## 🤝 Contributing
Your contributions can make this library even better! Feel free to open pull requests. For significant alterations, it's recommended to initiate an issue first to deliberate over the proposed changes. Don't forget to synchronize any test modifications accordingly.

## 📜 License
The Icosphere Generator Library is open-sourced under the MIT License. For comprehensive details, please refer to the MIT License documentation.
