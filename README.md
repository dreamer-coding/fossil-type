## **Fossil Type by Fossil Logic**

**Fossil Type** is a lightweight, cross-platform type system library written in pure C with optional C++ wrappers, designed to provide a stable and expressive foundation for type safety, casting, introspection, and functional adaptation across the Fossil ecosystem. Built for portability and long-term maintainability, Fossil Type introduces a unified set of core primitives, extended logical types, and runtime-safe conversion utilities without introducing runtime overhead or external dependencies.

Fossil Type acts as the structural backbone for higher-level libraries—enabling consistent type semantics across data processing, algorithms, AI systems, and infrastructure modules while remaining suitable for embedded and performance-critical environments.

### Key Features

- **Cross-Platform & ABI-Stable**  
  Provides a consistent type layer across Windows, macOS, Linux, and embedded targets with a C-friendly ABI and optional C++ class wrappers.

- **Unified Primitive & Logical Types**  
  Includes fixed-width integers, floating types, string references, pointer abstractions, tri-state logic (`tribool`), and extensible structural types such as `feature`, `combo`, and `ghost`.

- **Safe Casting & Conversion Model**  
  Supports both static and dynamic casting through explicit converter and adapter interfaces, enabling safe transformations between types without hidden runtime behavior.

- **Introspection & Functional Interfaces**  
  Built-in interfaces for type inspection, adaptation, and functional wrapping allow Fossil libraries to reason about types at runtime while remaining deterministic and auditable.

- **Zero External Dependencies**  
  Implemented entirely in portable C with optional C++ namespace wrappers, ensuring transparency, long-term stability, and suitability for restricted or audited environments.

- **Foundation for the Fossil Ecosystem**  
  Serves as the canonical type layer for Fossil Data, algorithm libraries, AI systems, and future infrastructure components—ensuring interoperability and predictable behavior across all modules.

## ***Prerequisites***

To get started, ensure you have the following installed:

- **Meson Build System**: If you don’t have Meson `1.8.0` or newer installed, follow the installation instructions on the official [Meson website](https://mesonbuild.com/Getting-meson.html).

### Adding Dependency

#### Adding via Meson Git Wrap

To add a git-wrap, place a `.wrap` file in `subprojects` with the Git repo URL and revision, then use `dependency('fossil-type')` in `meson.build` so Meson can fetch and build it automatically.

#### Integrate the Dependency:

Add the `fossil-type.wrap` file in your `subprojects` directory and include the following content:

```ini
[wrap-git]
url = https://github.com/fossillogic/fossil-type.git
revision = v0.1.0

[provide]
dependency_names = fossil-type
```

**Note**: For the best experience, always use the latest releases. Visit the [releases](https://github.com/fossillogic/fossil-type/releases) page for the latest versions.

## Build Configuration Options

Customize your build with the following Meson options:
	•	Enable Tests
To run the built-in test suite, configure Meson with:

```sh
meson setup builddir -Dwith_test=enabled
```

### Tests Double as Samples

The project is designed so that **test cases serve two purposes**:

- ✅ **Unit Tests** – validate the framework’s correctness.  
- 📖 **Usage Samples** – demonstrate how to use these libraries through test cases.  

This approach keeps the codebase compact and avoids redundant “hello world” style examples.  
Instead, the same code that proves correctness also teaches usage.  

This mirrors the **Meson build system** itself, which tests its own functionality by using Meson to test Meson.  
In the same way, Fossil Logic validates itself by demonstrating real-world usage in its own tests via Fossil Test.  

```bash
meson test -C builddir -v
```

Running the test suite gives you both verification and practical examples you can learn from.

## Contributing and Support

For those interested in contributing, reporting issues, or seeking support, please open an issue on the project repository or visit the [Fossil Logic Docs](https://fossillogic.com/docs) for more information. Your feedback and contributions are always welcome.
