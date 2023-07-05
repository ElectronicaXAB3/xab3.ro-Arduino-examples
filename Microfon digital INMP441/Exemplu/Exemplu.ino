#include <driver/i2s.h>

// configurari
#define SAMPLE_BUFFER_SIZE 300
#define SAMPLE_RATE 300
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT
//definire pini de pe microfon
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_4
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_15
#define I2S_MIC_SERIAL_DATA GPIO_NUM_13

// configurari legat de i2s
i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
    .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
    .communication_format = I2S_COMM_FORMAT_I2S,
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 8,
    .dma_buf_len = 64,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0
};

// asociere pini definiti cu i2s
i2s_pin_config_t i2s_mic_pins = {
    .bck_io_num = I2S_MIC_SERIAL_CLOCK,
    .ws_io_num = I2S_MIC_LEFT_RIGHT_CLOCK,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_MIC_SERIAL_DATA
};

void setup()
{
  Serial.begin(1000000);
  // initializare modul
  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &i2s_mic_pins);
}

int32_t raw_samples[SAMPLE_BUFFER_SIZE];
void loop()
{
  // citire date
  uint32_t max = 50000000; //variabile pentru ca plotterul sa nu faca scailing automat
  int32_t min = -50000000;
  size_t bytes_read = 0;
  i2s_read(I2S_NUM_0, raw_samples, sizeof(int32_t) * SAMPLE_BUFFER_SIZE, &bytes_read, portMAX_DELAY);
  int samples_read = bytes_read / sizeof(int32_t);
  //afisare date citite
  for (int i = 0; i < samples_read; i++){
      Serial.print(max); //plotterul sa nu faca scaling automat
      Serial.print(",");
      Serial.print(min);
      Serial.print(",");
      Serial.println(raw_samples[i]);
  }
}