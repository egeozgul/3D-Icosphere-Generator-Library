# Icosphere Generator Library

A lightweight C++ library for generating Icosphere meshes.

<div class="sketchfab-embed-wrapper"> <iframe title="printer v6" frameborder="0" allowfullscreen mozallowfullscreen="true" webkitallowfullscreen="true" allow="autoplay; fullscreen; xr-spatial-tracking" xr-spatial-tracking execution-while-out-of-viewport execution-while-not-rendered web-share src="https://sketchfab.com/models/0dcb5f802ad5404a830a89f99d20c65e/embed"> </iframe> <p style="font-size: 13px; font-weight: normal; margin: 5px; color: #4A4A4A;"> <a href="https://sketchfab.com/3d-models/printer-v6-0dcb5f802ad5404a830a89f99d20c65e?utm_medium=embed&utm_campaign=share-popup&utm_content=0dcb5f802ad5404a830a89f99d20c65e" target="_blank" rel="nofollow" style="font-weight: bold; color: #1CAAD9;"> printer v6 </a> by <a href="https://sketchfab.com/Ege.Ozgul?utm_medium=embed&utm_campaign=share-popup&utm_content=0dcb5f802ad5404a830a89f99d20c65e" target="_blank" rel="nofollow" style="font-weight: bold; color: #1CAAD9;"> _ </a> on <a href="https://sketchfab.com?utm_medium=embed&utm_campaign=share-popup&utm_content=0dcb5f802ad5404a830a89f99d20c65e" target="_blank" rel="nofollow" style="font-weight: bold; color: #1CAAD9;">Sketchfab</a></p></div>

<div align="center">
  <img src="icosphere.png" alt="Description of Image" width="500">
</div>

# Introduction

The Icosphere Generator provides an efficient way to generate vertices and indices for Icosphere meshes. An Icosphere is a polyhedron made up of equilateral triangle faces. It's often used in 3D graphics due to its even distribution of vertices which is particularly useful for applications like spherical environment mapping.

# Features

- Generate vertices and indices for an Icosphere mesh.
- Define the level of detail with the sample parameter.
- Efficient memory management for vertices and indices storage.

# Installation

To install the Icosphere Generator, simply include the `icosphere_generator.hpp` header in your project.

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
