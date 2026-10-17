# Universidad Nacional — Sede Regional Brunca
## EIF-201 — Programación I
### Proyecto: Simulador de Mundos (Etapa 1 y Etapa 2 — Laboratorio SFML)

**Integrantes del Equipo:**
* Dana Yajanis Guillén Trejos
* Gipzy María Vergara Valverde
* Raúl Fabricio Arias González

---

## 📖 Descripción del Proyecto
El **Simulador de Mundos** es una aplicación en C++ basada en Autómatas Celulares con topología esférica (**Toroide**) y arquitectura MVC. Permite simular el comportamiento, nacimiento, muerte y desempate entre tres especies distintas en mapas bidimensionales dinámicos.

---

## ⚙️ Reglas de la Simulación (Configuración Toroide)

1. **Especies y Símbolos Temáticos:**
   - **Especie 1 (A):** *Bacterias Alfa* (`A` / Verde)
   - **Especie 2 (B):** *Hongos Beta* (`B` / Cian)
   - **Especie 3 (C):** *Virus Gamma* (`C` / Magenta)
   - **Celda Vacía:** (`.` / Gris)

2. **Vecindario:**
   - Cada celda evalúa sus **8 celdas vecinas** a su alrededor (vecindario de Moore).
   - Los bordes se envuelven mediante la topología **Toroide** (`(fila + delta + filas) % filas`).

3. **Condiciones de Nacimiento ($N$) y Supervivencia ($S$):**
   - **Nacimiento ($N$):** Una celda vacía nace si el total de vecinos vivos está en $N = \{3\}$.
   - **Supervivencia ($S$):**
     - *Bacterias Alfa (E1):* $S_1 = \{2, 3\}$
     - *Hongos Beta (E2):* $S_2 = \{3, 4\}$
     - *Virus Gamma (E3):* $S_3 = \{1, 2\}$

4. **Regla de Desempate (`resolveTie`):**
   - Cuando nace una nueva celda en una posición vacía, hereda la especie que posea **mayor presencia entre sus vecinos**.
   - En caso de empate en el conteo máximo, se resuelve favoreciendo a la especie con **mayor índice** (evaluando de E3 a E1).

---

## 🚀 Guía de Uso del Programa (Interfaz SFML)

- **Clic Izquierdo:** Colocar la especie seleccionada en la cuadrícula.
- **Clic Derecho:** Borrar celda (marcar vacía).
- **[Espacio]:** Avanzar 1 generación.
- **[N]:** Cambiar al siguiente mundo activo del laboratorio.
- **[D]:** Duplicar el mundo activo actual.
- **[1 - 3]:** Cambiar la especie activa para siembra manual.