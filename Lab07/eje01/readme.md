## Ejercicio 01

Crear una clase Configuracion que almacene las configuraciones generales del sistema (por ejemplo, idioma y zona horaria).
• Asegúrate de que solo exista una instancia de esta clase.
• Añade un método `mostrar_configuracion()` que imprima los valores actuales.
• Verifica en el main que aunque crees varios objetos, todos apunten al mismo.

## Solución

Implementamos el **patrón Singleton**:

- Constructor privado para evitar instanciación directa
- Método `getInstance()` que siempre retorna la misma instancia
- Prevención de copia y asignación
- Estado global compartido

## Verificación

Al crear múltiples referencias, todas muestran la misma dirección de memoria, demostrando que es el mismo objeto.

```cpp
Configuracion& config1 = Configuracion::getInstance();
Configuracion& config2 = Configuracion::getInstance();
```