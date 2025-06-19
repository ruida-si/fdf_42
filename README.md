# ![My Icon](https://raw.githubusercontent.com/ruida-si/fdf_42/main/terrain.jpeg) FDF

**FDF** is a wireframe 3D terrain renderer developed in C using the MiniLibX graphics library. It reads a 2D heightmap from a file and visualizes it in an isometric.

This project is part of the **42 School curriculum** and aims to build understanding of graphics rendering, 3D projections, and file parsing.

<p align="center">
  <img src="path/to/demo.gif" alt="FDF Demo" width="600"/>
</p>

---

## 🧠 Key Concepts

- **Isometric projection** for 3D effect
- **DDA line algorithm** for drawing lines between points
- Parsing heightmaps from `.fdf` files

---

## 🔧 Features

- Support for various map sizes and heights
- Isometric projection
- Color gradients based on height
---

## 🗺️ Map Format

Map files are plain text with space-separated integers representing height values (z-axis). Example:

```plaintext
0 0 0 0
0 10 10 0
0 10 10 0
0 0 0 0
