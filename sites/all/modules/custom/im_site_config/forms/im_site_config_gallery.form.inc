<?php
/**
 * @file
 * Form for gallery blocks.
 */

/**
 * Image form():
 */
function im_site_config_gallery_form($form, &$form_state){
  // Image.
  $form['im_image_one'] = array(
		'#title' => t('Image'),
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
		);
  $form['im_image_one']['im_banner'] = array(
    '#title' => t('Image:'),
    '#type' => 'managed_file',
    '#description' => t('Upload the image for the banner.'),
    '#default_value' => variable_get('im_banner', ''),
    '#upload_location' => 'public://uploads',
    );
  $form['im_image_one']['im_banner_style'] = array(
    '#title' => t('Image Style'),
    '#type' => 'select',
    '#options' => im_get_image_styles(),
    '#default_value' => variable_get('im_banner_style', 2),
    '#access' => user_access('administer site configuration'),
    '#description' => t('Select the image style for the prices.'),
    );

  // PDF.
  $form['im_image_two'] = array
(  	'#title' => t('PDF Image'),
  	'#type' => 'fieldset',
  	'#collapsible' => FALSE,
  	'#collapsed' => FALSE,
  	);
  $form['im_image_two']['im_pdf_image'] = array(
  	'#title' => t('Image:'),
  	'#type' => 'managed_file',
  	'#description' => t('Upload the image for the pdf.'),
  	'#default_value' => variable_get('im_pdf_image', ''),
  	'#upload_location' => 'public://uploads',
  	);
  $form['im_image_two']['im_pdf_file'] = array(
    '#title' => t('PDF File:'),
    '#type' => 'managed_file',
    '#description' => t('Upload the pdp file'),
    '#default_value' => variable_get('im_pdf_file', ''),
    '#upload_location' => 'public://uploads',
    );
  $form['im_image_two']['im_pdf_style'] = array(
  	'#title' => t('Image Style'),
  	'#type' => 'select',
  	'#options' => im_get_image_styles(),
  	'#default_value' => variable_get('im_pdf_style', 2),
  	'#access' => user_access('administer site configuration'),
  	'#description' => t('Select the image style for the pdf.')
  	);
  $form['im_image_two']['im_pdf_link'] = array(
    '#title' => t('Link:'),
    '#type' => 'textfield',
    '#format' => 'full_html',
    '#description' => t('Here, you can write the link for the image'),
    '#default_value' => variable_get('im_pdf_link'),
    );

  // Estimator.
  $form['im_image_three'] = array(
  	'#title' => t('Estimator'),
  	'#type' => 'fieldset',
  	'#collapsible' => FALSE,
  	'#collapsed' => FALSE,
  	);
  $form['im_image_three']['im_estimator_image'] = array(
  	'#title' => t('Estimator Image'),
  	'#type' => 'managed_file',
  	'#description' => t('Upload the image for the estimator'),
  	'#default_value' => variable_get('im_estimator_image', ''),
  	'#upload_location' => 'public://uploads',
  	);
  $form['im_image_three']['im_estimator_style'] = array(
  	'#title' => t('Image Style'),
  	'#type' => 'select',
  	'#options' => im_get_image_styles(),
  	'#default_value' => variable_get('im_estimator_style', 2),
  	'#access' => user_access('administer site configuration'),
  	);
  $form['im_image_three']['im_estimator_link'] = array(
  	'#title' => t('Estimator Link'),
  	'#type' => 'textfield',
  	'#format' => 'full_html',
  	'#description' => t('Here, you can write the link for the image'),
  	'#default_value' => variable_get('im_estimator_link', ''),
  	);

  //Service
  $form['im_image_four'] = array(
  	'#title' => t('Technical Service'),
  	'#type' => 'fieldset',
  	'#collapsible' => FALSE,
  	'#collapsed' => FALSE,
  	);
  $form['im_image_four']['im_service_image'] = array(
  	'#title' => t('Service Image'),
  	'#type' => 'managed_file',
  	'#description' => t('Upload the image for the service'),
  	'#default_value' => variable_get('im_service_image', ''),
  	'#upload_location' => 'public://uploads',
  	);
  $form['im_image_four']['im_service_style'] = array(
  	'#title' => t('Image Style'),
  	'#type' => 'select',
  	'#options' => im_get_image_styles(),
  	'#default_value' => variable_get('im_service_style', 2),
  	'#access' => user_access('administer site configuration'),
  	);
  $form['im_image_four']['im_service_link'] = array(
  	'#title' => t('Service Link'),
  	'#type' => 'textfield',
  	'#format' => 'full_html',
  	'#description' => t('Here, you can write the link for the image.'),
  	'#default_value' => variable_get('im_service_link', ''),
  	);

  // Submit
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('submit'),
    );
  return $form;
}

/*
 * Submits the form.
 */
function im_site_config_gallery_form_submit($form, &$form_state){
  
 // Images.
	$images = array(
		'im_banner',
		'im_pdf_image',
    'im_pdf_file',
    'im_estimator_image',
    'im_service_image',
		);
	foreach ($images as $key => $image) {
		if ($form_state['values'][$image]) {
			// Load the file via file.fid.
			$file = file_load($form_state['values'][$image]);
			// Change status to permanent.
			$file->status = FILE_STATUS_PERMANENT;
			// Save.
			file_save($file);
			// Record that the module (in this example, user module) is using the file.
			file_usage_add($file, 'im_site_config', 'module', $file->fid);
			// Set the variables.
			variable_set($image, $form_state['values'][$image]);
		}
	}

	// Styles
	$styles = array(
		'im_banner_style',
		'im_pdf_style',
		'im_estimator_style',
		'im_service_style',
		);
	foreach ($styles as $key => $style) {
		if (isset($form_state['values'][$style])){
			variable_set($style, $form_state['values'][$style]);
		}
	}

	$links = array(
		'im_pdf_link',
		'im_estimator_link',
		'im_service_link',
		);
	foreach ($links as $key => $link){
		if (isset($form_state['values'][$link])) {
			variable_set($link, $form_state['values'][$link]);
		}
	}
	drupal_set_message(t('Changes saved'));
 }



