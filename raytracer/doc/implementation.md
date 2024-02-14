**Here's a Guide that will help you in your process while creating your own components into the Raytracer.**

# General Functionment of the Raytracer:

This Raytracer is a program that will render images in .bpm from a Scene file, you can check out the syntax of the Scene in Core/Parzer/scenes.

You can create your own Light / Primitives (cube, cylinder, cone and many more), by using our interface in the Core/Primitives and Core/Lights.

The parser will read the scene file and create a Scene object, which will contain all the objects of the scene, and the lights, which will then be sent to the Raytracer for rendering.

# Creating your own Primitives:

To create your own primitives, you will need to create a class that inherits from the Primitive class, and implement the following functions:

```cpp
        virtual const Color getColor() const = 0; // Return the color of the primitive (RGB)
        virtual bool hits(RayTracer::Ray& ray) = 0; // Check if the primitive is hit by a ray given in parameter
        virtual double racine(RayTracer::Ray& ray) = 0; // Get the distance between the ray and the primitive
        virtual Math::Vector3D getNormal(Math::Point3D hitPoint) = 0; // Get the normal of the primitive at a given point
        virtual Math::Point3D hitPoint(RayTracer::Ray& ray) = 0; // Get the hit point of the primitive
        virtual void setParams(const std::vector<double> params) = 0; // Set the parameters of the primitive
```

The first function is used to get the color of the primitive, the second one is used to check if the primitive is hit by a ray, the third one is used to get the distance between the ray and the primitive, the fourth one is used to get the normal of the primitive at a given point, the fifth one is used to get the hit point of the primitive, and the last one is used to set the parameters of the primitive.

You can check out the Sphere class in Primitives/SPHERE/ to see how it's done.

# Creating your own Lights:

To create your own lights, you will need to create a class that inherits from the Light class, and implement the following functions:

```cpp
        virtual void cast(RayTracer::IPrimitive &x, Math::Point3D &hitPoint, RayTracer::Scene &scene) = 0; // Cast the light on a primitive, using the hitPoint and the scene
        virtual void setParams(const std::vector<double> params) = 0; // Set the parameters of the light
```

The first function is used to cast the light on a primitive, the second one is used to set the parameters of the light.

You can check out the PointLight class in Lights/DIRECTIONAL/ to see how it's done.

# Plugins

The plugins file contains all the .so generated upon compilation of the project, you can add your own .so files in this folder, and they will be loaded upon execution of the program. These mainly contain the primitives and lights that you will create.

# Scene file

The scene file is a file that contains all the objects and lights of the scene, you can check out the syntax of the scene in Core/Parser/scenes.

Scene files are parser by the parser, which you can extend to support your own Primitives. Scene files are loaded uppon the program execution, by giving its path as a parameter to the program.

Here is the different things you can add in the scene file:

```c
scene : // Mandatory
{
        camera : // There only can be one so far
        {
                resolution :
                {
                        width : foo;
                        height : bar;
                };
                position :
                {
                        x : foo;
                        y : bar;
                        z : baz;
                };
                rotation :
                {
                        x : foo;
                        y : bar;
                        z : baz;
                };
                fieldOfView : foo;
        };
        primitives :
        {
                spheres =
                ( // ( = list of spheres, even tho there's only one, you need to use it)
                        {
                                x = foo;
                                y = bar;
                                z = baz;
                                r = foo;
                                color =
                                {
                                        r = foo;
                                        g = bar;
                                        b = baz;
                                };
                        }
                )
        }
        lights :
        {
                ambient = foo;
                diffuse = foo;
                point = (
                        {
                                x = foo;
                                y = bar;
                                z = baz;
                        }
                );
        }
}
```

You can add your own primitives to the parser by adding them in the Core/Parzer/, they will be automatically added to the Scene object that is sent to the Raytracer. Remember that your own primitives must use IPrimitive Interface to be added to the Scene & Rendered by the Raytracer.