cmd_/home/virtual/Desktop/Custom_Driver/USB_Driver_Controller/driver.mod := printf '%s\n'   driver.o | awk '!x[$$0]++ { print("/home/virtual/Desktop/Custom_Driver/USB_Driver_Controller/"$$0) }' > /home/virtual/Desktop/Custom_Driver/USB_Driver_Controller/driver.mod
