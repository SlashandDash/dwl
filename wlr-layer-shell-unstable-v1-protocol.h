/* Generated by wayland-scanner 1.22.0 */

#ifndef WLR_LAYER_SHELL_UNSTABLE_V1_SERVER_PROTOCOL_H
#define WLR_LAYER_SHELL_UNSTABLE_V1_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_wlr_layer_shell_unstable_v1 The wlr_layer_shell_unstable_v1 protocol
 * @section page_ifaces_wlr_layer_shell_unstable_v1 Interfaces
 * - @subpage page_iface_zwlr_layer_shell_v1 - create surfaces that are layers of the desktop
 * - @subpage page_iface_zwlr_layer_surface_v1 - layer metadata interface
 * @section page_copyright_wlr_layer_shell_unstable_v1 Copyright
 * <pre>
 *
 * Copyright © 2017 Drew DeVault
 *
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 * </pre>
 */
struct wl_output;
struct wl_surface;
struct xdg_popup;
struct zwlr_layer_shell_v1;
struct zwlr_layer_surface_v1;

#ifndef ZWLR_LAYER_SHELL_V1_INTERFACE
#define ZWLR_LAYER_SHELL_V1_INTERFACE
/**
 * @page page_iface_zwlr_layer_shell_v1 zwlr_layer_shell_v1
 * @section page_iface_zwlr_layer_shell_v1_desc Description
 *
 * Clients can use this interface to assign the surface_layer role to
 * wl_surfaces. Such surfaces are assigned to a "layer" of the output and
 * rendered with a defined z-depth respective to each other. They may also be
 * anchored to the edges and corners of a screen and specify input handling
 * semantics. This interface should be suitable for the implementation of
 * many desktop shell components, and a broad number of other applications
 * that interact with the desktop.
 * @section page_iface_zwlr_layer_shell_v1_api API
 * See @ref iface_zwlr_layer_shell_v1.
 */
/**
 * @defgroup iface_zwlr_layer_shell_v1 The zwlr_layer_shell_v1 interface
 *
 * Clients can use this interface to assign the surface_layer role to
 * wl_surfaces. Such surfaces are assigned to a "layer" of the output and
 * rendered with a defined z-depth respective to each other. They may also be
 * anchored to the edges and corners of a screen and specify input handling
 * semantics. This interface should be suitable for the implementation of
 * many desktop shell components, and a broad number of other applications
 * that interact with the desktop.
 */
extern const struct wl_interface zwlr_layer_shell_v1_interface;
#endif
#ifndef ZWLR_LAYER_SURFACE_V1_INTERFACE
#define ZWLR_LAYER_SURFACE_V1_INTERFACE
/**
 * @page page_iface_zwlr_layer_surface_v1 zwlr_layer_surface_v1
 * @section page_iface_zwlr_layer_surface_v1_desc Description
 *
 * An interface that may be implemented by a wl_surface, for surfaces that
 * are designed to be rendered as a layer of a stacked desktop-like
 * environment.
 *
 * Layer surface state (layer, size, anchor, exclusive zone,
 * margin, interactivity) is double-buffered, and will be applied at the
 * time wl_surface.commit of the corresponding wl_surface is called.
 *
 * Attaching a null buffer to a layer surface unmaps it.
 *
 * Unmapping a layer_surface means that the surface cannot be shown by the
 * compositor until it is explicitly mapped again. The layer_surface
 * returns to the state it had right after layer_shell.get_layer_surface.
 * The client can re-map the surface by performing a commit without any
 * buffer attached, waiting for a configure event and handling it as usual.
 * @section page_iface_zwlr_layer_surface_v1_api API
 * See @ref iface_zwlr_layer_surface_v1.
 */
/**
 * @defgroup iface_zwlr_layer_surface_v1 The zwlr_layer_surface_v1 interface
 *
 * An interface that may be implemented by a wl_surface, for surfaces that
 * are designed to be rendered as a layer of a stacked desktop-like
 * environment.
 *
 * Layer surface state (layer, size, anchor, exclusive zone,
 * margin, interactivity) is double-buffered, and will be applied at the
 * time wl_surface.commit of the corresponding wl_surface is called.
 *
 * Attaching a null buffer to a layer surface unmaps it.
 *
 * Unmapping a layer_surface means that the surface cannot be shown by the
 * compositor until it is explicitly mapped again. The layer_surface
 * returns to the state it had right after layer_shell.get_layer_surface.
 * The client can re-map the surface by performing a commit without any
 * buffer attached, waiting for a configure event and handling it as usual.
 */
extern const struct wl_interface zwlr_layer_surface_v1_interface;
#endif

#ifndef ZWLR_LAYER_SHELL_V1_ERROR_ENUM
#define ZWLR_LAYER_SHELL_V1_ERROR_ENUM
enum zwlr_layer_shell_v1_error {
	/**
	 * wl_surface has another role
	 */
	ZWLR_LAYER_SHELL_V1_ERROR_ROLE = 0,
	/**
	 * layer value is invalid
	 */
	ZWLR_LAYER_SHELL_V1_ERROR_INVALID_LAYER = 1,
	/**
	 * wl_surface has a buffer attached or committed
	 */
	ZWLR_LAYER_SHELL_V1_ERROR_ALREADY_CONSTRUCTED = 2,
};
#endif /* ZWLR_LAYER_SHELL_V1_ERROR_ENUM */

#ifndef ZWLR_LAYER_SHELL_V1_LAYER_ENUM
#define ZWLR_LAYER_SHELL_V1_LAYER_ENUM
/**
 * @ingroup iface_zwlr_layer_shell_v1
 * available layers for surfaces
 *
 * These values indicate which layers a surface can be rendered in. They
 * are ordered by z depth, bottom-most first. Traditional shell surfaces
 * will typically be rendered between the bottom and top layers.
 * Fullscreen shell surfaces are typically rendered at the top layer.
 * Multiple surfaces can share a single layer, and ordering within a
 * single layer is undefined.
 */
enum zwlr_layer_shell_v1_layer {
	ZWLR_LAYER_SHELL_V1_LAYER_BACKGROUND = 0,
	ZWLR_LAYER_SHELL_V1_LAYER_BOTTOM = 1,
	ZWLR_LAYER_SHELL_V1_LAYER_TOP = 2,
	ZWLR_LAYER_SHELL_V1_LAYER_OVERLAY = 3,
};
#endif /* ZWLR_LAYER_SHELL_V1_LAYER_ENUM */

/**
 * @ingroup iface_zwlr_layer_shell_v1
 * @struct zwlr_layer_shell_v1_interface
 */
struct zwlr_layer_shell_v1_interface {
	/**
	 * create a layer_surface from a surface
	 *
	 * Create a layer surface for an existing surface. This assigns
	 * the role of layer_surface, or raises a protocol error if another
	 * role is already assigned.
	 *
	 * Creating a layer surface from a wl_surface which has a buffer
	 * attached or committed is a client error, and any attempts by a
	 * client to attach or manipulate a buffer prior to the first
	 * layer_surface.configure call must also be treated as errors.
	 *
	 * After creating a layer_surface object and setting it up, the
	 * client must perform an initial commit without any buffer
	 * attached. The compositor will reply with a
	 * layer_surface.configure event. The client must acknowledge it
	 * and is then allowed to attach a buffer to map the surface.
	 *
	 * You may pass NULL for output to allow the compositor to decide
	 * which output to use. Generally this will be the one that the
	 * user most recently interacted with.
	 *
	 * Clients can specify a namespace that defines the purpose of the
	 * layer surface.
	 * @param layer layer to add this surface to
	 * @param namespace namespace for the layer surface
	 */
	void (*get_layer_surface)(struct wl_client *client,
				  struct wl_resource *resource,
				  uint32_t id,
				  struct wl_resource *surface,
				  struct wl_resource *output,
				  uint32_t layer,
				  const char *namespace);
	/**
	 * destroy the layer_shell object
	 *
	 * This request indicates that the client will not use the
	 * layer_shell object any more. Objects that have been created
	 * through this instance are not affected.
	 * @since 3
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
};


/**
 * @ingroup iface_zwlr_layer_shell_v1
 */
#define ZWLR_LAYER_SHELL_V1_GET_LAYER_SURFACE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_shell_v1
 */
#define ZWLR_LAYER_SHELL_V1_DESTROY_SINCE_VERSION 3

#ifndef ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ENUM
#define ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ENUM
/**
 * @ingroup iface_zwlr_layer_surface_v1
 * types of keyboard interaction possible for a layer shell surface
 *
 * Types of keyboard interaction possible for layer shell surfaces. The
 * rationale for this is twofold: (1) some applications are not interested
 * in keyboard events and not allowing them to be focused can improve the
 * desktop experience; (2) some applications will want to take exclusive
 * keyboard focus.
 */
enum zwlr_layer_surface_v1_keyboard_interactivity {
	/**
	 * no keyboard focus is possible
	 *
	 * This value indicates that this surface is not interested in
	 * keyboard events and the compositor should never assign it the
	 * keyboard focus.
	 *
	 * This is the default value, set for newly created layer shell
	 * surfaces.
	 *
	 * This is useful for e.g. desktop widgets that display information
	 * or only have interaction with non-keyboard input devices.
	 */
	ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_NONE = 0,
	/**
	 * request exclusive keyboard focus
	 *
	 * Request exclusive keyboard focus if this surface is above the
	 * shell surface layer.
	 *
	 * For the top and overlay layers, the seat will always give
	 * exclusive keyboard focus to the top-most layer which has
	 * keyboard interactivity set to exclusive. If this layer contains
	 * multiple surfaces with keyboard interactivity set to exclusive,
	 * the compositor determines the one receiving keyboard events in
	 * an implementation- defined manner. In this case, no guarantee is
	 * made when this surface will receive keyboard focus (if ever).
	 *
	 * For the bottom and background layers, the compositor is allowed
	 * to use normal focus semantics.
	 *
	 * This setting is mainly intended for applications that need to
	 * ensure they receive all keyboard events, such as a lock screen
	 * or a password prompt.
	 */
	ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_EXCLUSIVE = 1,
	/**
	 * request regular keyboard focus semantics
	 *
	 * This requests the compositor to allow this surface to be
	 * focused and unfocused by the user in an implementation-defined
	 * manner. The user should be able to unfocus this surface even
	 * regardless of the layer it is on.
	 *
	 * Typically, the compositor will want to use its normal mechanism
	 * to manage keyboard focus between layer shell surfaces with this
	 * setting and regular toplevels on the desktop layer (e.g. click
	 * to focus). Nevertheless, it is possible for a compositor to
	 * require a special interaction to focus or unfocus layer shell
	 * surfaces (e.g. requiring a click even if focus follows the mouse
	 * normally, or providing a keybinding to switch focus between
	 * layers).
	 *
	 * This setting is mainly intended for desktop shell components
	 * (e.g. panels) that allow keyboard interaction. Using this option
	 * can allow implementing a desktop shell that can be fully usable
	 * without the mouse.
	 * @since 4
	 */
	ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ON_DEMAND = 2,
};
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ON_DEMAND_SINCE_VERSION 4
#endif /* ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ENUM */

#ifndef ZWLR_LAYER_SURFACE_V1_ERROR_ENUM
#define ZWLR_LAYER_SURFACE_V1_ERROR_ENUM
enum zwlr_layer_surface_v1_error {
	/**
	 * provided surface state is invalid
	 */
	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_SURFACE_STATE = 0,
	/**
	 * size is invalid
	 */
	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_SIZE = 1,
	/**
	 * anchor bitfield is invalid
	 */
	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_ANCHOR = 2,
	/**
	 * keyboard interactivity is invalid
	 */
	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_KEYBOARD_INTERACTIVITY = 3,
};
#endif /* ZWLR_LAYER_SURFACE_V1_ERROR_ENUM */

#ifndef ZWLR_LAYER_SURFACE_V1_ANCHOR_ENUM
#define ZWLR_LAYER_SURFACE_V1_ANCHOR_ENUM
enum zwlr_layer_surface_v1_anchor {
	/**
	 * the top edge of the anchor rectangle
	 */
	ZWLR_LAYER_SURFACE_V1_ANCHOR_TOP = 1,
	/**
	 * the bottom edge of the anchor rectangle
	 */
	ZWLR_LAYER_SURFACE_V1_ANCHOR_BOTTOM = 2,
	/**
	 * the left edge of the anchor rectangle
	 */
	ZWLR_LAYER_SURFACE_V1_ANCHOR_LEFT = 4,
	/**
	 * the right edge of the anchor rectangle
	 */
	ZWLR_LAYER_SURFACE_V1_ANCHOR_RIGHT = 8,
};
#endif /* ZWLR_LAYER_SURFACE_V1_ANCHOR_ENUM */

/**
 * @ingroup iface_zwlr_layer_surface_v1
 * @struct zwlr_layer_surface_v1_interface
 */
struct zwlr_layer_surface_v1_interface {
	/**
	 * sets the size of the surface
	 *
	 * Sets the size of the surface in surface-local coordinates. The
	 * compositor will display the surface centered with respect to its
	 * anchors.
	 *
	 * If you pass 0 for either value, the compositor will assign it
	 * and inform you of the assignment in the configure event. You
	 * must set your anchor to opposite edges in the dimensions you
	 * omit; not doing so is a protocol error. Both values are 0 by
	 * default.
	 *
	 * Size is double-buffered, see wl_surface.commit.
	 */
	void (*set_size)(struct wl_client *client,
			 struct wl_resource *resource,
			 uint32_t width,
			 uint32_t height);
	/**
	 * configures the anchor point of the surface
	 *
	 * Requests that the compositor anchor the surface to the
	 * specified edges and corners. If two orthogonal edges are
	 * specified (e.g. 'top' and 'left'), then the anchor point will be
	 * the intersection of the edges (e.g. the top left corner of the
	 * output); otherwise the anchor point will be centered on that
	 * edge, or in the center if none is specified.
	 *
	 * Anchor is double-buffered, see wl_surface.commit.
	 */
	void (*set_anchor)(struct wl_client *client,
			   struct wl_resource *resource,
			   uint32_t anchor);
	/**
	 * configures the exclusive geometry of this surface
	 *
	 * Requests that the compositor avoids occluding an area with
	 * other surfaces. The compositor's use of this information is
	 * implementation-dependent - do not assume that this region will
	 * not actually be occluded.
	 *
	 * A positive value is only meaningful if the surface is anchored
	 * to one edge or an edge and both perpendicular edges. If the
	 * surface is not anchored, anchored to only two perpendicular
	 * edges (a corner), anchored to only two parallel edges or
	 * anchored to all edges, a positive value will be treated the same
	 * as zero.
	 *
	 * A positive zone is the distance from the edge in surface-local
	 * coordinates to consider exclusive.
	 *
	 * Surfaces that do not wish to have an exclusive zone may instead
	 * specify how they should interact with surfaces that do. If set
	 * to zero, the surface indicates that it would like to be moved to
	 * avoid occluding surfaces with a positive exclusive zone. If set
	 * to -1, the surface indicates that it would not like to be moved
	 * to accommodate for other surfaces, and the compositor should
	 * extend it all the way to the edges it is anchored to.
	 *
	 * For example, a panel might set its exclusive zone to 10, so that
	 * maximized shell surfaces are not shown on top of it. A
	 * notification might set its exclusive zone to 0, so that it is
	 * moved to avoid occluding the panel, but shell surfaces are shown
	 * underneath it. A wallpaper or lock screen might set their
	 * exclusive zone to -1, so that they stretch below or over the
	 * panel.
	 *
	 * The default value is 0.
	 *
	 * Exclusive zone is double-buffered, see wl_surface.commit.
	 */
	void (*set_exclusive_zone)(struct wl_client *client,
				   struct wl_resource *resource,
				   int32_t zone);
	/**
	 * sets a margin from the anchor point
	 *
	 * Requests that the surface be placed some distance away from
	 * the anchor point on the output, in surface-local coordinates.
	 * Setting this value for edges you are not anchored to has no
	 * effect.
	 *
	 * The exclusive zone includes the margin.
	 *
	 * Margin is double-buffered, see wl_surface.commit.
	 */
	void (*set_margin)(struct wl_client *client,
			   struct wl_resource *resource,
			   int32_t top,
			   int32_t right,
			   int32_t bottom,
			   int32_t left);
	/**
	 * requests keyboard events
	 *
	 * Set how keyboard events are delivered to this surface. By
	 * default, layer shell surfaces do not receive keyboard events;
	 * this request can be used to change this.
	 *
	 * This setting is inherited by child surfaces set by the get_popup
	 * request.
	 *
	 * Layer surfaces receive pointer, touch, and tablet events
	 * normally. If you do not want to receive them, set the input
	 * region on your surface to an empty region.
	 *
	 * Keyboard interactivity is double-buffered, see
	 * wl_surface.commit.
	 */
	void (*set_keyboard_interactivity)(struct wl_client *client,
					   struct wl_resource *resource,
					   uint32_t keyboard_interactivity);
	/**
	 * assign this layer_surface as an xdg_popup parent
	 *
	 * This assigns an xdg_popup's parent to this layer_surface. This
	 * popup should have been created via xdg_surface::get_popup with
	 * the parent set to NULL, and this request must be invoked before
	 * committing the popup's initial state.
	 *
	 * See the documentation of xdg_popup for more details about what
	 * an xdg_popup is and how it is used.
	 */
	void (*get_popup)(struct wl_client *client,
			  struct wl_resource *resource,
			  struct wl_resource *popup);
	/**
	 * ack a configure event
	 *
	 * When a configure event is received, if a client commits the
	 * surface in response to the configure event, then the client must
	 * make an ack_configure request sometime before the commit
	 * request, passing along the serial of the configure event.
	 *
	 * If the client receives multiple configure events before it can
	 * respond to one, it only has to ack the last configure event.
	 *
	 * A client is not required to commit immediately after sending an
	 * ack_configure request - it may even ack_configure several times
	 * before its next surface commit.
	 *
	 * A client may send multiple ack_configure requests before
	 * committing, but only the last request sent before a commit
	 * indicates which configure event the client really is responding
	 * to.
	 * @param serial the serial from the configure event
	 */
	void (*ack_configure)(struct wl_client *client,
			      struct wl_resource *resource,
			      uint32_t serial);
	/**
	 * destroy the layer_surface
	 *
	 * This request destroys the layer surface.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * change the layer of the surface
	 *
	 * Change the layer that the surface is rendered on.
	 *
	 * Layer is double-buffered, see wl_surface.commit.
	 * @param layer layer to move this surface to
	 * @since 2
	 */
	void (*set_layer)(struct wl_client *client,
			  struct wl_resource *resource,
			  uint32_t layer);
};

#define ZWLR_LAYER_SURFACE_V1_CONFIGURE 0
#define ZWLR_LAYER_SURFACE_V1_CLOSED 1

/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_CONFIGURE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_CLOSED_SINCE_VERSION 1

/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_SET_SIZE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_SET_ANCHOR_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_SET_EXCLUSIVE_ZONE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_SET_MARGIN_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_SET_KEYBOARD_INTERACTIVITY_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_GET_POPUP_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_ACK_CONFIGURE_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_SET_LAYER_SINCE_VERSION 2

/**
 * @ingroup iface_zwlr_layer_surface_v1
 * Sends an configure event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwlr_layer_surface_v1_send_configure(struct wl_resource *resource_, uint32_t serial, uint32_t width, uint32_t height)
{
	wl_resource_post_event(resource_, ZWLR_LAYER_SURFACE_V1_CONFIGURE, serial, width, height);
}

/**
 * @ingroup iface_zwlr_layer_surface_v1
 * Sends an closed event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zwlr_layer_surface_v1_send_closed(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, ZWLR_LAYER_SURFACE_V1_CLOSED);
}

#ifdef  __cplusplus
}
#endif

#endif
