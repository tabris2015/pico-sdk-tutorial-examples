#include "pico/stdlib.h"
#include "hardware/pwm.h"
#define LED_PIN 16


void setup(uint pin, uint slice, uint channel)
{
    // configurar gpio
    gpio_init(pin);
    gpio_set_function(pin, GPIO_FUNC_PWM);
    // configurar modulo PWM
    pwm_set_clkdiv(slice, 1.0);
    pwm_set_wrap(slice, 200);
    pwm_set_chan_level(slice, channel, 0);
    pwm_set_enabled(slice, true);
}

int main()
{
    uint slice =  pwm_gpio_to_slice_num(LED_PIN);
    uint channel = pwm_gpio_to_channel(LED_PIN);
    setup(LED_PIN, slice, channel);
    // bucle principal
    while(true)
    {
        //subida
        for(int i = 0; i <= 200; i++)
        {
            // encender el led con brillo bajo
            pwm_set_chan_level(slice, channel, i);
            sleep_ms(10);
        }
        //bajada
        for(int i = 200; i >= 0; i--)
        {
            // encender el led con brillo bajo
            pwm_set_chan_level(slice, channel, i);
            sleep_ms(10);
        }
    }
}