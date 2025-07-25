   extern "C" void kernel_main() {
       const char *str = "Hello, 64-bit OS!";
       char *vidptr = (char*) 0xb8000; // Video memory
       unsigned int i = 0;

       while (str[i] != '\0') {
           vidptr[i * 2] = str[i]; // Character
           vidptr[i * 2 + 1] = 0x07; // Attribute-byte: light grey on black
           i++;
       }

       while (1); // Loop forever
   }
   
