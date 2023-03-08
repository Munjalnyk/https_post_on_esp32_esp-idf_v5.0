#include "esp_http_client.h"


esp_err_t client_event_post_handler(esp_http_client_event_handle_t evt)
{
    switch (evt->event_id)
    {
    case HTTP_EVENT_ON_DATA:
        printf("HTTP_EVENT_ON_DATA: %.*s\n", evt->data_len, (char *)evt->data);
        break;

    default:
        break;
    }
    return ESP_OK;
}






static void post_rest_function_on()
{
    esp_http_client_config_t config_post = {
        .url = "https://fcm.googleapis.com/fcm/send",
        .method = HTTP_METHOD_POST,
        .cert_pem = NULL,
        .event_handler = client_event_post_handler,
        .transport_type = HTTP_TRANSPORT_OVER_SSL};

    esp_http_client_handle_t client = esp_http_client_init(&config_post);

    char *post_data = "{\"to\": \"/topics/Example_topic\",\"notification\":{\"body\": \"Example_body\",\"title\": \"Example_title\",\"image\":\"https://www.google.com/example_image.jpg\"}}";

    esp_http_client_set_post_field(client, post_data, strlen(post_data));
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_header(client, "Authorization", "key=AAAA-GVlxYk:AP_Example_key");

    esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}





static void post_rest_function_off()
{
    esp_http_client_config_t config_post = {
        .url = "https://fcm.googleapis.com/fcm/send",
        .method = HTTP_METHOD_POST,
        .cert_pem = NULL,
        .event_handler = client_event_post_handler,
        .transport_type = HTTP_TRANSPORT_OVER_SSL};

    esp_http_client_handle_t client = esp_http_client_init(&config_post);

    char *post_data = "{\"to\": \"/topics/Example_topic\",\"notification\":{\"body\": \"Example_body\",\"title\": \"Example_title\",\"image\":\"https://www.google.com/example_image.jpg\"}}";

    esp_http_client_set_post_field(client, post_data, strlen(post_data));
    esp_http_client_set_header(client, "Content-Type", "application/json");
    esp_http_client_set_header(client, "Authorization", "key=AAAA-GVlxYk:AP_Example_key");

    esp_http_client_perform(client);
    esp_http_client_cleanup(client);
}


void app_main(void){
     post_rest_function_on();
     post_rest_function_off();
     vTaskDelay(5000 / portTICK_PERIOD_MS);
}
